n = int(input())
ans = set()
cnt = 0
for a in range(1, n + 1):
    for b in range(a, n + 1):
        if 0 < a ^ b <= n:
            q = sorted([a, b, a ^ b])
            if q[2] < q[0] + q[1]:
                cnt += 1
                ans.add(q[2] * 10 ** 9 + q[1] * 10 ** 5 + q[0])
print(len(ans))