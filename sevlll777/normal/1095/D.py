n = int(input())
sosed = dict()
for c in range(n):
    sosed[c+1] = set()
z1, z2 = map(int, input().split())
sosed[z1].add(z2)
sosed[z2].add(z1)
i = [z1, z2]
for __ in range(1, n):
    z1, z2 = map(int, input().split())
    sosed[z1].add(z2)
    sosed[z2].add(z1)
    if z1 == 1 or z2 == 1:
        if max(z1, z2) in i:
            i = [max(z1, z2)]
pred = set()
cnt = 0
i = i[0]
print(1, end=" ")
pred.add(1)
while cnt < n-1:
    cnt += 1
    print(i, end=" ")
    pred.add(i)
    for y in sosed[i]:
        if y not in pred:
            i = y