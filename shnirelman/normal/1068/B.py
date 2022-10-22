import math

b = int(input())
ans = 0
a = int(math.sqrt(b))

for i in range(1, a + 1):
    if(b % i == 0):
        ans += 2
        
if(a * a == b):
    ans -= 1
print(ans)