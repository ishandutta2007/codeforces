n,m = map(int, input().split())

def prime (x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True

bad = False
for i in range (n+1, m):
    if prime (i):
        bad = True
if prime (m) == False:
    bad = True

print ('NO' if bad else 'YES')