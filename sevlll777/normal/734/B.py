k1, k2, k3, k4 = map(int, input().split())
x = min(k1, k3, k4)
k1 -= x
print(x * 256 + min(k1, k2) * 32)