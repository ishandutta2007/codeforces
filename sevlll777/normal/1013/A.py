n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
if sum(A) >= sum(B):
    print('Yes')
else:
    print('No')