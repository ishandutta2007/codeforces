n = input()
arr = map(int, raw_input().split())

ans = 0
x = {}
for i in arr:
    if i in x:
        del x[i]
    else:
        x[i] = 0
    
    if ans < len(x):
        ans = len(x)
        
print ans