n = int(input())
s = input()
A = list(map(int, input().split()))
t = 'hard'
dph = [0] * (n + 1)
for i in range(n):
    dph[i + 1] = dph[i] + A[i] * (s[i] == 'h')
dpha = [0] * (n + 1)
for i in range(n):
    if s[i] != 'a':
        dpha[i + 1] = dpha[i]
    else:
        dpha[i + 1] = min(dpha[i] + A[i], dph[i])
dphar = [0] * (n + 1)
for i in range(n):
    if s[i] != 'r':
        dphar[i + 1] = dphar[i]
    else:
        dphar[i + 1] = min(dphar[i] + A[i], dpha[i])
dphard = [0] * (n + 1)
for i in range(n):
    if s[i] != 'd':
        dphard[i + 1] = dphard[i]
    else:
        dphard[i + 1] = min(dphard[i] + A[i], dphar[i])
print(dphard[-1])