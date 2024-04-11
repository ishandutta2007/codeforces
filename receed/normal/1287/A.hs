solve [] = (0, 0)
solve (x:s) | x == 'P' = (a + 1, b)
            | x == 'A' = (0, max a b)
    where (a, b) = solve s


go n = do
    k <- getLine
    a <- getLine
    putStrLn $ show $ snd $ solve a
    if n > 1 then do
        go $ n - 1
    else
        return ()

main = do
    s <- getLine
    let n = read s
    go n