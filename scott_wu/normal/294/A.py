n = int(input())

arr = []
arr.append (0)
for x in (input().split()):
    arr.append (int(x))
#arr.append (input().split())
arr.append (0)

m = int(input())

for i in range(m):
    x,y = map (int, input().split())

    #print (x)
    #print (y)
    #print (arr)
    
    arr[x-1] += y - 1
    arr[x+1] += arr[x] - y
    arr[x] = 0

for i in range (1, n + 1):
    print (arr[i])