n = input()
B = [0 for i in range(7)]
while len(n) != 7:
    n = '0' + n
ans = 0
for i in range(7):
    ans = max(ans, int(n[i]))
    B[i] = int(n[i])
print(ans)
s = ''
for i in range(ans):
    cur = [0 for i in range(7)]
    for j in range(7):
        if B[j] > 0:
            cur[j] = 1
            B[j] -= 1
    was = False
    for j in range(7):
        if cur[j] == 1:
            s += '1'
            was = True
        elif was:
            s += '0'
    s += ' '
print(s[:-1])