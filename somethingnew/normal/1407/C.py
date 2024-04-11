n = int(input())
pos = 1
lst = [-1 for i in range(n)]
for i in range(2, n + 1):
    print(f"? {pos} {i}")
    n1 = int(input())
    print(f"? {i} {pos}")
    n2 = int(input())
    if n1 > n2:
        lst[pos - 1] = n1
        pos = i
    else:
        lst[i - 1] = n2
sm = n * (n + 1) // 2 - 1 - sum(lst)
for i in range(n):
    if lst[i] == -1:
        lst[i] = sm
        break
print("!", *lst)