n = int(input())
marks = list(map(int, input().split()))
marks.sort()
i = 0
while sum(marks) < 4.5*n:
    marks[i] = 5
    i += 1
print(i)