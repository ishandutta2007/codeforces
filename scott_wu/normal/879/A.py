n = input()

cs = 0
for i in range(n):
    s, d = map(int, raw_input().split())
    while cs < s or cs % d != s % d:
        cs += 1
    cs += 1

print cs - 1