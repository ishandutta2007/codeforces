r, g, b = map(int, input().split())
r, g, b = sorted([r, g, b])
s1 = (r + g + b) // 3
s2 = r + g
print(min(s1, s2))