n = int(input())
mass = list(map(int, input().split()))
he = 1
cnt = 1
for u in range(len(mass)-1):
    if mass[u] * 2 < mass[u+1]:
        he = max(he, cnt)
        cnt = 1
    else:
        cnt += 1
print(max(cnt, he))