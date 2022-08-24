n = input()
arr = map(int, raw_input().split())

ans, cval = 0, 0
for i in arr:
    if i == -1 and not cval:
        ans += 1
    else:
        cval += i
print ans