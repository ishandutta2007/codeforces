a = int(input(), 2)
ans = 0
for i in range(0, 100):
    if(4 ** i < a):
        ans += 1
        
print(ans)