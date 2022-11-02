n = int(input())
a = input().split()
for i in range(n):
    a[i] = int(a[i])
a.sort()
#print(a)
ans = 0
for i in range(n // 2):
    ans += (int(a[i]) + int(a[n - i - 1])) * (int(a[i]) + int(a[n - i - 1])) 
print(ans)