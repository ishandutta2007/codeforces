n = int(raw_input())
arr = map (int, raw_input().split())

res = n - 1
while res > 0 and arr[res] > arr[res-1]:
    res -= 1
print res