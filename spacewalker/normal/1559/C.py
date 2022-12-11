t = int(input())
for tc in range(t):
    n = int(input())
    s = input().replace(" ", "")
    if s[-1] == '0':
        ans = [*range(1, n + 1), n + 1]
        print(*ans)
    elif s[0] == '1':
        ans = [n + 1, *range(1, n + 1)]
        print(*ans)
    elif "01" in s:
        i = s.index("01")
        ans = [*range(1, i + 2), n + 1, *range(i + 2, n + 1)]
        print(*ans)
    else:
        print(-1)