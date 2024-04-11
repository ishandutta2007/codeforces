n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))
    
f = True
for i in range(n):
    for j in range(n):
        if arr[i][j] > 1:
            b = False
            for k in range(n):
                for l in range(n):
                    if arr[i][j] == arr[i][k] + arr[l][j]:
                        b = True
            if not b:
                f = False
print("Yes" if f else "No")