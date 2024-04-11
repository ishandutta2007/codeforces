n = input()
arr = list(map(int, input().split()))
print(sum(max(arr) - i for i in arr))