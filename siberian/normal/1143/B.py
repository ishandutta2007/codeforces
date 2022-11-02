from sys import setrecursionlimit
setrecursionlimit(10**9)

def check(a):
    ans = 1
    a = int(a)
    while (a):
        ans *= a % 10
        a //= 10
    return ans

def ans(a, b, cnt):
    max_right = 0
    ans_right = 0
    max_mid = 0
    ans_mid = 0
    x = 9**(cnt)
    ans_right = b + (cnt) * '9'
    max_right = check(ans_right)
    a = int(a)
    b = int(b)
    while (a % 10 != 9):
        a += 1
    while (b % 10 != 9):
        b -= 1
    if (a > b):
        return max_right, ans_right
    a = str(a)
    b = str(b)
    a = (len(b) - len(a)) * '0' + a
    if (a != b and len(a) > 1):
        max_mid, ans_mid = ans(a[:-1], b[:-1], cnt + 1)
    else:
        ans_mid = b + '9'*(cnt)
        max_mid = check(ans_mid)
    if (max_right > max_mid):
        return max_right, ans_right
    return max_mid, ans_mid

mass_b = [1]

def get(a, b):
    global mass_b
    a = str(a)
    b = str(b)
    a = (len(b) - len(a)) * '0' + a
    for i in b:
        mass_b.append(mass_b[-1] * int(i))
        
    return int(ans(a, b, 0)[1])

def main():
    a = input()
    print(check(get(1, a)))

main()