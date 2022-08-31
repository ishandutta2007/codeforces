cv = 20000
f = True
n = int(input())

for i in range(n):
    x, s = input().split()
    x = int(x)
    if s in ['East', 'West'] and (cv == 20000 or cv == 0):
        f = False
    if s == 'North':
        cv += x
    if s == 'South':
        cv -= x
    
    if cv < 0 or cv > 20000:
        f = False
if cv != 20000:
    f = False

print("Yes" if f else "No")