def proverka(k, a, s):
    b = []
    for i in a:
        b.append(i)
    for i in range(len(b)):
        b[i] = b[i] + k * (i + 1)
    b.sort()
    cnt = 0
    index = 0
    while(cnt < k and s - b[index] >= 0):
        cnt += 1
        s -= b[index]
        index += 1
    if(cnt < k):
        return False
    else:
        return True
n, s = map(int, input().split())
a = list(map(int, input().split()))
l = 0
r = n + 1
while(l + 1 < r):
    if(proverka((l+r)//2, a, s)):
        l = (l+r)//2
    else:
        r = (l+r)//2
for i in range(n):
    a[i] = a[i] + l * (i + 1)
a.sort()
qwer = 0
index = 0
while(index < l and qwer + a[index] <=  s):
    qwer += a[index]
    index += 1
print(l, qwer)