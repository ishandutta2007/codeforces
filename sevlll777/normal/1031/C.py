a, b = list(map(int, input().split()))
x = (a + b)
n = int((1 + 8 * x) ** 0.5 / 2 - 0.5)
flag = 0
if a > b:
    a, b = b, a
    flag = 1
ar1 = []
num1 = 0
for i in range(n, 0, -1):
    if a - num1 >= i:
        ar1.append(i)
        num1 += i
ar2 = []
for i in range(1, n + 1):
    if i not in ar1:
        ar2.append(i)
if flag == 0:
    print(len(ar1))
    print(' '.join(map(str, ar1)))
    print(len(ar2))
    print(' '.join(map(str, ar2)))
else:
    print(len(ar2))
    print(' '.join(map(str, ar2)))
    print(len(ar1))
    print(' '.join(map(str, ar1)))