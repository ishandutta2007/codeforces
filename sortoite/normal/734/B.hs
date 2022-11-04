main = do
    [k2, k3, k5, k6] <- (map read . words) `fmap` getLine :: IO [Integer]
    let x = minimum [k2,k5,k6]
    let y = minimum [k2-x, k3]
    print $ x * 256 + y * 32