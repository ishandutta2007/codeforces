d, k, a, b, t = map(int, input().split())
if d <= k:
    print(d * a)
elif t + k * a > k * b:
    print(k * a + (d - k) * b)
else:
    cnt = d // k
    print(k * cnt * a + (cnt - 1) * t + min(t + (d % k) * a, (d % k) * b))