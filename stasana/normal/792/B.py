def plus(a):
    global n
    a += 1
    a = a % n
    return a

n, k = map(int, input().split())
a = list(map(int, input().split()))
p = [1]*n
qwer = n
index = 0
for i in range(k):
    res = 0
    while res != a[i]%qwer:
        index = plus(index)
        res += p[index]
    p[index] = 0
    qwer -= 1
    print(index + 1, end = " ")
    while p[index] != 1 :
        index = plus(index)