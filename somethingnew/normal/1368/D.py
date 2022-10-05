def solve():
    nm = [0 for i in range(21)]
    step = [1]
    for i in range(20):
        step.append(step[-1] * 2)
    n = int(input())
    lst = list(map(int,input().split()))
    for i in range(n):
        num = lst[i]
        st = 0
        while num:
            ar = num % 2
            nm[st] += ar
            num //= 2
            st += 1
    ans = 0
    for i in range(n):
        rnum = 0
        for j in range(21):
            if nm[j] > 0:
                nm[j] -= 1
                rnum += step[j]
        ans += rnum * rnum
    print(ans)
for i in range(1):
    solve()