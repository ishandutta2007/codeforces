a, b, c = map(int, input().split())
print("YES" if (a + b + c) % 2 == 0 and c >= max(a,-a) + max(b,-b) else "NO")