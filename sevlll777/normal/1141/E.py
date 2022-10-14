H, n = map(int, input().split())
D = list(map(int, input().split()))
for i in range(1, n):
    D[i] += D[i - 1]
w = -min(D)
if D[-1] >= 0 and w < H:
    print(-1)
    exit(0)
if D[-1] >= 0 or w >= H:
    for q in range(n):
        i = D[q]
        if -i >= H:
            print(q + 1)
            exit(0)
cnt = 0
cnt += n * ((H - w - D[-1] - 1) // (-D[-1]))
sas = H - cnt // n * (-D[-1])
for q in range(n):
    i = D[q]
    if -i >= sas:
        print(cnt + q + 1)
        break