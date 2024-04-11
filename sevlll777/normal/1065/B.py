n, m = map(int, input().split())
t = 0
while t*(t-1)//2 < m:
    t += 1
print(max(0, n-2*m), max(0, n-t))