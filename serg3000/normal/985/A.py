n = int (input())
a = list(map(int,input().split()))
a.sort()
b = [0] * (n // 2)
b[0] = 2
for i in range(1, n // 2):
    b[i] = b[i - 1] + 2
cnt  = 0;
for i in range(n // 2):
    cnt += abs(a[i] - b[i])
c = 0
for i in range(n // 2):
    c += abs(a[i] - (b[i] - 1))
print(min(c,cnt))