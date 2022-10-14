def gen(n):
    if n == 1:
        yield '0'
        yield '1'
    else:
        for s in gen(n - 1):
            yield s+'0'
            yield s +'1'


n, l, r, x = map(int, input().split())
cnt = 0
C = list(map(int, input().split()))
for pos in gen(n):
    A = []
    for i in range(n):
        if pos[i] == '1':
            A.append(C[i])
    A.sort()
    if len(A):
        if l <= sum(A) <= r and A[-1] - A[0] >= x:
            cnt += 1
print(cnt)