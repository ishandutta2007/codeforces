n,k = map (int, input().split())

arr = list (map (int, input().split()))
arr.sort()
arr.reverse()

print (-1 if k > n else str(arr[k-1]) + ' 0')