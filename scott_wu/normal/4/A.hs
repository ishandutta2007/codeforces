ans 1 = "NO"
ans 4 = "YES"
ans 2 = "NO"
ans x = ans (x - 2)

main = do
    [a] <- fmap (map read . words) getLine
    putStrLn (ans a)