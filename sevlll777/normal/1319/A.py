n = int(input())
R = list(map(int, input().split()))
B = list(map(int, input().split()))
c1 = 0
c2 = 0
for i in range(n):
    if R[i] == 1 and B[i] == 0:
        c1 += 1
    elif R[i] == 0 and B[i] == 1:
        c2 += 1
if c1 == 0:
    print(-1)
else:
    print(1 + c2 // c1)