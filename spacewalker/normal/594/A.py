n = int(input())
arr = [*map(int, input().split())]
arr = sorted(arr)

print(min([b - a for a, b in zip(arr[:n//2], arr[n//2:])]))