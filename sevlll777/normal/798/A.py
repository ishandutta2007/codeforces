s = input()
cnt = 0
for i in range(len(s) // 2):
    if s[i] != s [-i-1]:
        cnt += 1
if cnt == 1 or (cnt == 0 and len(s) % 2):
    print('YES')
    exit(0)
print('NO')