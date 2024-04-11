n = int(input())
A = list(map(int, input().split()))
a = A.count(2)
b = n - a
if a > b:
    print(b)
else:
    print(a + (b - a) // 3)