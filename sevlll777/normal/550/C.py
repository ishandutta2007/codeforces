s = input()
s = '00' + s
n = len(s)
for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            if (4 * int(s[i]) + 2 * int(s[j]) + int(s[k])) % 8 == 0:
                print('YES')
                print(int(s[i] + s[j] + s[k]))
                exit(0)
print('NO')