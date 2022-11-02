a = input().split()
n = int(a[0])
k = int(a[1])
if n >= k:
    print((k - 1)//2)
elif (k > (2*n - 1)):
    print(0)
else:
    print((k - 1) // 2 - (k - n - 1))