a, b = map(int, raw_input().strip().split())
c, d = map(int, raw_input().strip().split())
print max(abs(a - c), abs(b - d))