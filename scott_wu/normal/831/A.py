n = input()
arr = [int(x) for x in raw_input().split()]

b = 0
cv = 0
for i in range(n-1):
    ov = 0
    if arr[i] == arr[i+1]:
        ov = 1
    elif arr[i] > arr[i+1]:
        ov = 2
    
    if ov < cv:
        b = -1
    cv = ov

print "NO" if b == -1 else "YES"