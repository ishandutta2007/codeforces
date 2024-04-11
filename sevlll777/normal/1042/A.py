n = int(input())
m = int(input())
A = []
for _ in range(n):
    A.append(int(input()))
l = -1
r = 10 ** 9
while r - l > 1:
    mid = (l + r) // 2
    c = 0
    for i in A:
        if mid >= i:
            c += max(0, mid - i)
        else:
            c = -111
            break
    if c >= m:
        r = mid
    else:
        l = mid
print(l + 1, max(A) + m)