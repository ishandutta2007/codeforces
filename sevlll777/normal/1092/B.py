n = int(input())
mass = list(map(int, input().split()))
mass.sort()
cnt = 0
for i in range(0, n, 2):
    cnt += mass[i+1] - mass[i]
print(cnt)