for _ in range(int(input())):
    n = int(input())
    P = list(map(int, input().split()))
    ans = [0] * n
    for i in range(n):
        if ans[i] == 0:
            now = i
            cnt = 0
            cll = []
            while True:
                now = P[now] - 1
                cnt += 1
                cll.append(now)
                if now == i:
                    break
            for u in cll:
                ans[u] = cnt
    print(' '.join(list(map(str, ans))))