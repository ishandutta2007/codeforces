import sys
input=sys.stdin.readline


def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
def solve(n,m):
    if n % (m ** 2):
        return -1
    x = n // (m ** 2)
    table1 = prime_factorize(x)
    if len(table1) <= 1:
        return -1
    cnt = 2
    while x % m == 0:
        cnt += 1
        x //=m
    if cnt == 2 and len(table1) >= 2:
        return 1
    if cnt == 2 and len(table1) <= 1:
        return -1
    table3 = prime_factorize(x)
    table2 = prime_factorize(m)
    #print(table2,table3,cnt)
    if cnt == 3:
        if len(table3) == 0:
            if len(table2) == 1:
                return -1
            return 1
        if len(table3) == 1:
            if len(table2) == 1 or (len(table2) == 2 and table2[0] == table2[1] == table3[0]):
                return -1
        return 1
    if cnt > 3:
        if len(table2) == 1 and len(table3) <= 1:
            return -1
        return 1
t = int(input())
for i in range(t):
    n,m=map(int,input().split())
    a = solve(n,m)
    if a == 1:
        print('YES')
    else:
        print('NO')