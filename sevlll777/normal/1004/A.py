a, d = map(int, input().split())
mass = list(map(int, input().split()))
cnt = 2
for i in range(0, a-1):
    if mass[i+1] - mass[i] > 2*d:
        cnt += 2
    elif mass[i+1] - mass[i] == 2*d:
        cnt += 1
print(cnt)