n = int(input())
A = list(map(int, input().split()))
z = max(A)
cnt = 0
hop = 0
for i in A:
    hop = max(hop, cnt)
    if i == z:
        cnt += 1
    else:
        cnt = 0
hop = max(hop, cnt)
print(hop)