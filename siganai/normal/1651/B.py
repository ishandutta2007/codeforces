import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n = int(input())
    ans = [1]
    for i in range(1,n):
        tmp = ans[-1] * 3
        if tmp > 10 ** 9:
            print('NO')
            break
        ans.append(ans[-1] * 3)
    else:
        print('YES')
        print(*ans)