n, m, r = map(int, input().split())
S = list(map(int, input().split()))
B = list(map(int, input().split()))
x = min(S)
y = max(B)
cnt = r % x
act = r // x
cnt += act * y
print(max(r, cnt))