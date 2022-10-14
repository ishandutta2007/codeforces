n, k = map(int, input().split())
mass = list(map(int, input().split()))
e = mass.count(1)
s = mass.count(-1)
popq = float('-inf')
for b in range(0, k):
    e1=e
    s1=s
    for vkladki in range(b, n, k):
        if mass[vkladki] == 1:
            e1 -= 1
        else:
            s1 -= 1
    popq = max(popq, abs(e1-s1))
print(popq)