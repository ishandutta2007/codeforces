x = int(input())
arr = input().split()
arri = []
for i in range(len(arr)):
    arri.append(int(arr[i]))

print(max(arri) ^ arri[-1])