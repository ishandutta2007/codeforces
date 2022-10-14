n = int(input())
A = list(map(int, input().split()))
even = {}
odd = {}
cnt = 0
B = [A[0]]
for i in range(1, n):
    B.append(B[-1] ^ A[i])
for u in B:
    even[u] = 0
    odd[u] = 0
for x in range(n):
    if x % 2 == 0:
        even[B[x]] += 1
    else:
        odd[B[x]] += 1
for t in even:
    cnt += even[t]*(even[t] - 1) // 2
    cnt += odd[t]*(odd[t] - 1) // 2
if 0 in odd:
    print(cnt + odd[0])
else:
    print(cnt)