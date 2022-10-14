n, x = map(int, input().split())
A = list(map(int, input().split()))
if len(A) != len(set(A)):
    print(0)
    exit(0)
Q = []
for i in A:
    if i & x != i:
        Q.append(i & x)
if len(set(Q).intersection(set(A))) > 0:
    print(1)
elif len(set(Q)) != len(Q):
    print(2)
else:
    print(-1)