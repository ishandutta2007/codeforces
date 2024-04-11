arr = input().split()
n = int(arr[0])
k = int(arr[1])
arr_1 = input().split()
for i in range(n):
    arr_1[i] = int(arr_1[i])
# TODO
x = arr_1[k - 1]
res = 0
for i in range(n):
    if arr_1[i] >= x and arr_1[i] > 0:
        res += 1
print(res)