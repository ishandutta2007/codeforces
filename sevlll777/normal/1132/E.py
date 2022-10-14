import time
import random
W = int(input())
M = [int(a) for a in input().split()]
A = [0] * 8
sTime = time.time()

s = 0
mi = 10**20
for i in range(8):
    if s + M[i]*(i+1) <= W:
        s += M[i]*(i+1)
        A[i] = M[i]
    else:
        t = (W-s)//(i+1)
        s += t*(i+1)
        A[i] += t
    
    if s <= W:
        mi = min(mi, W-s)

while time.time() - sTime < 1.7:
    i = random.randrange(8)
    a = random.randrange(2)
    if W-s >= 20 or (s-W < 10 and a == 0):
        if A[i] < M[i]:
            A[i] += 1
            s += (i+1)
    else:
        if A[i] > 0:
            A[i] -= 1
            s -= (i+1)

    if s <= W:
        mi = min(mi, W-s)

print(W-mi)