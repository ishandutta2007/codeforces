from collections import deque
n = int(input())
A = deque(list(map(int, input().split())))
B = deque(list(map(int, input().split())))
A.popleft()
B.popleft()
for i in range(3 * 10 ** 6):
    if len(A) == 0:
        print(i, 2)
        exit(0)
    elif len(B) == 0:
        print(i, 1)
        exit(0)
    else:
        x = A.popleft()
        y = B.popleft()
        if x > y:
            A.append(y)
            A.append(x)
        else:
            B.append(x)
            B.append(y)
print(-1)