m = int(input())

pw = 0
cur = 1
f = 1

while pw < m:
    cur += 1
    k = cur
    while k % 5 == 0:
        k //= 5
        pw += 1

if pw > m:
    print(0)
else:
    print(5)
    print(cur, cur + 1, cur + 2, cur + 3, cur + 4)